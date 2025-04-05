#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


/** 
 * WAVE file consists of a file header followed by data chunks
 * Each file has a single "wave" chunk which consists of:
 * 1) "fmt" chunk to specify the data format
 * 2) "data" chunk that contains the sample data
 *
 * https://docs.fileformat.com/audio/wav/ 
 * */
typedef struct {
	// RIFF chunk descriptor
	uint32_t chunk_id;     // == "WAVE" (big-endian)
	uint32_t chunk_size;
	uint32_t format;
	// FMT sub-chunk
	uint32_t subchunk1_id;  // == "FMT " (big-endian)
	uint32_t subchunk1_size;
	uint16_t audio_format;
	uint16_t num_channels;
	uint32_t sample_rate;
	uint32_t byte_rate;
	uint16_t block_align;
	uint16_t bits_per_sample;
	// DATA sub-chunk
	uint32_t subchunk2_id;   // == "DATA" (big-endian)
	uint32_t subchunk2_size; // bytes in actual data
} __attribute__((packed)) header_t;

int write_wav(uint8_t samples[], uint32_t num_samples) {
	header_t wav;
	// RIFF chunk descriptor
	memcpy(&wav.chunk_id, "RIFF", 4);
	wav.chunk_size = sizeof(header_t) + num_samples * sizeof(num_samples) - 8;
	memcpy(&wav.format, "WAVE", 4);
	// FMT sub-chunk
	memcpy(&wav.subchunk1_id, "fmt ", 4);
	wav.subchunk1_size = 16;  // sizeof rest of subchunk
	wav.audio_format = 1;     // PCM
	wav.num_channels = 1;     // MONO
	wav.sample_rate = 44100;
	wav.bits_per_sample = 8;
	wav.byte_rate = wav.sample_rate * wav.num_channels * wav.bits_per_sample / 8;
	// DATA sub-chunk
	memcpy(&wav.subchunk2_id, "data", 4);  // == "DATA" (big-endian)
	wav.subchunk2_size = num_samples * wav.num_channels * wav.bits_per_sample / 8;

	FILE *f = fopen("output.wav", "w");
	if (!f) {
		perror("Error while opening 'output.wav'\n");
	}
	int err = fwrite(&wav, sizeof(wav), 1, f);
	if (!err) {
		perror("Error while writing header to 'output.wav'\n");
	}
	err = fwrite(samples, sizeof(*samples), num_samples, f);
	if (!err) {
		perror("Error while writing data to 'output.wav'\n");
	}
	return 0;
}

int main() {
	uint32_t num_samples = 44100;
	uint8_t data[num_samples];
	write_wav(data, num_samples);
}
