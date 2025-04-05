#include <stdint.h>
#include <string.h>

#include "wav.h"


int main() {
	uint32_t num_samples = SAMPLE_RATE * 4;  // four seconds
	uint8_t data[num_samples];
	memset(data, 0, num_samples);
	// Major Triad: A-C#-E
	add_tone(data, num_samples, 440, 255);
	add_tone(data + SAMPLE_RATE, num_samples - SAMPLE_RATE, 554, 255);
	add_tone(data + SAMPLE_RATE * 2, num_samples - SAMPLE_RATE * 2, 659, 255);
	write_wav(data, num_samples);
}
