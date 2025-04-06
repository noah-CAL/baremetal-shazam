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
#include <stdint.h>
#include <string.h>

#include "data.h"
#include "wav.h"

void major_triad() {
	uint32_t num_samples = SAMPLE_RATE * 4;  // four seconds
	uint8_t data[num_samples];
	memset(data, 0, num_samples);
	// Major Triad: A-C#-E
	add_tone(data, num_samples, 440, 255);
	add_tone(data + SAMPLE_RATE, num_samples - SAMPLE_RATE, 554, 255);
	add_tone(data + SAMPLE_RATE * 2, num_samples - SAMPLE_RATE * 2, 659, 255);
	write_wav(data, num_samples);
}

int main() {
	uint32_t num_samples = SAMPLE_RATE;  // four seconds
	add_tone(data, num_samples, 440, 255);
	write_wav(data, num_samples);
}
