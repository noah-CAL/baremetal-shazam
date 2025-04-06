/* 
 * Shazam algorithm in "baremetal" C!
 *
 * Copyright (C) 2025 Noah Sedlik
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef WAV_H
#define WAV_H

#define AUDIO_FORMAT 1    // Pulse-Code Modulation (PCM)
#define NUM_CHANNELS 1
#define SAMPLE_RATE 44100
#define BITS_PER_SAMPLE 8


int write_wav(uint8_t samples[], uint32_t num_samples);
void add_tone(uint8_t data[], uint32_t num_samples, uint32_t freq, uint8_t magnitude);

#endif
