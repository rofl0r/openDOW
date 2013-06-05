#include "../c-flod/backends/wave_format.h"
#include "../c-flod/flashlib/ByteArray.h"

struct player {
	int play_waveslot;
	struct ByteArray wave_streams[1];
	struct ByteArray out_wave;
	WAVE_HEADER_COMPLETE wavhdr;
} playa;

static int handle_overflow(int *sample) {
	if(*sample > 32767) {
		*sample = 32767;
		return 1;
	} else if (*sample < -32768) {
		*sample = -32768;
		return -1;
	}
	return 0;
}

void upsample() {
	struct ByteArray* mine = &playa.wave_streams[0];
	struct ByteArray* out = &playa.out_wave;
	
	if(!mine->bytesAvailable(mine)) return;
	
	size_t i = 0;
	size_t upsample_factor = 44100 / playa.wavhdr.wave_hdr.samplerate;
	size_t readbytes = playa.wavhdr.wave_hdr.bitwidth == 8 ? 1 : 2;
	int chan[2] = { 0, 0 };
	int next[2];
	
	while(mine->bytesAvailable(mine)) {
		int16_t sound;
		size_t c, u;
		for(c = 0; c < 2; c++) {
			if(c < playa.wavhdr.wave_hdr.channels) {
				if(readbytes == 1) next[c] = ((uint8_t) ByteArray_readByte(mine) - 128) * 256;
				else next[c] = ByteArray_readShort(mine);
				handle_overflow(&next[c]);
			} else 
				next[c] = next[c - 1];
		}
		for(u = 0; u < upsample_factor; u++) {
			for(c = 0; c < 2; c++) {
				int interpolated = u == 0 ? chan[c] : 
					chan[c] + ((next[c]-chan[c]) * ((float)u/(float)upsample_factor));
				ByteArray_writeShort(out, interpolated);
			}
		}
		for (c=0; c<2; c++) chan[c] = next[c];
	}

	return;
}

static char buf[1024* 1024];

int main(int argc, char ** argv) {
	struct ByteArray *ba = &playa.wave_streams[0];
	ByteArray_ctor(ba);
	if(!ByteArray_open_file(ba, argv[1])) return 1; 
	ByteArray_set_endian(ba, BAE_LITTLE);
	ByteArray_readMultiByte(ba, (void*) &playa.wavhdr, sizeof(WAVE_HEADER_COMPLETE));
	struct ByteArray *out = &playa.out_wave;
	ByteArray_ctor(out);
	ByteArray_set_endian(out, BAE_LITTLE);
	ByteArray_open_mem(out, buf, sizeof buf);
	upsample();
	ByteArray_dump_to_file(out, "test.raw");
	
}

