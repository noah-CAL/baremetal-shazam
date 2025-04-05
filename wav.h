#define AUDIO_FORMAT 1    // Pulse-Code Modulation (PCM)
#define NUM_CHANNELS 1
#define SAMPLE_RATE 44100
#define BITS_PER_SAMPLE 8


int write_wav(uint8_t samples[], uint32_t num_samples);
void add_tone(uint8_t data[], uint32_t num_samples, uint32_t freq, uint8_t magnitude);
