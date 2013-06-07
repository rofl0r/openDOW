#define FILESIZE 3678
#define SAMPLERATE 5512
#define BITS 8
#define CHANS 1
#define FMTC0 1
#define FMTC1 0
#define DATASIZE 3633
#define STRUCT_NAME scream

static const struct {
	WAVE_HEADER_COMPLETE header;
	uint8_t data[FILESIZE - sizeof(WAVE_HEADER_COMPLETE)];
} STRUCT_NAME = { 
	{
		{ { 'R', 'I', 'F', 'F'}, FILESIZE -8, { 'W', 'A', 'V', 'E'} },
		{ { 'f', 'm', 't', ' '}, 16, {{FMTC0, FMTC1}}, CHANS, SAMPLERATE, SAMPLERATE * CHANS * BITS/8, CHANS * BITS/8, BITS },
		{ { 'd', 'a', 't', 'a' }, DATASIZE }
	},
	{
		80,36,47,48,60,68,80,103,135,160,182,153,130,132,131,150,173,209,206,190,191,152,133,125,104,95,93,102,96,116,148,149,
		131,103,74,51,48,46,29,56,100,129,160,158,141,130,127,136,154,197,231,236,235,220,176,109,67,76,76,75,88,74,88,106,
		108,134,128,116,117,114,119,112,107,84,69,95,120,121,110,115,135,155,166,198,235,235,235,211,160,105,55,46,54,55,52,52,
		77,130,172,181,186,165,134,130,117,114,89,54,61,68,90,115,134,150,154,186,204,184,153,108,86,90,102,126,124,96,87,99,
		111,119,131,146,140,150,195,222,220,191,140,84,54,72,101,120,108,82,85,82,85,137,179,166,148,118,102,137,154,178,178,131,
		109,85,80,119,159,166,158,143,99,57,45,56,72,99,133,179,216,216,224,192,124,86,59,54,65,86,105,122,154,167,164,151,
		138,119,102,109,95,76,71,67,79,102,133,154,171,193,201,200,186,165,151,134,98,69,69,83,89,97,115,129,135,140,142,165,
		202,202,182,158,127,109,74,52,61,65,49,47,74,92,122,157,190,189,158,150,133,128,130,132,160,187,208,193,161,130,90,80,
		97,113,115,100,95,83,58,64,78,90,111,129,143,146,146,148,159,165,154,157,177,175,162,150,108,72,54,42,67,121,157,165,
		174,150,120,99,81,116,142,154,168,164,153,116,96,92,93,114,115,124,143,148,150,143,140,144,135,115,107,100,94,89,69,70,
		78,79,103,129,152,163,167,175,170,167,149,128,124,115,125,147,156,158,146,135,119,109,115,114,116,124,139,152,142,135,136,128,
		118,118,113,91,66,50,46,48,76,118,146,162,166,167,164,159,153,148,153,155,165,159,144,141,124,122,127,132,137,135,155,162,
		149,129,109,91,61,55,64,68,69,75,89,88,86,95,100,117,134,155,184,193,195,189,171,151,140,148,148,146,150,145,134,123,
		114,111,114,118,115,108,108,112,110,111,108,106,112,115,117,129,141,142,140,133,125,121,124,130,128,121,113,110,108,103,104,111,
		119,125,140,144,140,148,155,162,166,164,162,156,148,141,141,134,122,116,109,102,97,86,73,70,68,67,79,91,103,127,146,144,
		146,156,162,164,172,182,178,171,163,141,111,112,114,101,112,113,108,107,103,107,101,97,105,118,125,129,129,125,130,134,139,145,
		150,154,158,155,148,145,134,127,126,124,117,106,97,90,96,101,106,112,114,112,103,106,114,122,135,149,149,140,136,139,153,158,
		157,152,146,145,139,129,118,116,111,103,104,102,105,108,113,120,126,142,150,145,138,130,122,113,114,117,120,126,118,109,111,112,
		121,131,138,147,150,148,141,136,134,131,129,128,123,119,120,118,118,121,126,133,137,139,138,133,129,122,118,125,130,128,122,118,
		114,106,102,105,107,113,121,127,133,132,128,127,130,136,141,146,148,147,145,144,148,150,148,141,131,121,111,103,101,102,101,102,
		101,102,107,116,123,131,137,139,144,149,151,152,149,143,134,124,120,118,112,111,114,118,122,127,131,128,123,123,120,122,127,131,
		135,136,138,140,140,135,130,127,124,124,122,122,122,116,112,113,114,116,123,129,131,132,130,130,128,124,124,126,128,132,133,132,
		134,134,133,133,131,130,132,132,127,124,124,122,120,118,117,118,121,124,123,121,121,123,126,128,129,131,134,135,136,135,134,132,
		129,126,123,124,123,121,120,119,120,122,126,130,133,133,130,128,129,129,130,131,130,129,128,127,126,125,125,125,126,125,124,124,
		122,121,122,123,124,124,127,128,129,132,133,133,134,132,129,127,127,127,127,126,125,126,127,128,128,128,129,128,127,127,126,127,
		126,125,123,123,123,123,124,126,128,129,131,132,133,132,130,128,125,126,125,127,125,125,125,124,127,126,130,129,131,129,129,129,
		128,130,125,130,121,133,101,53,137,218,196,152,128,51,38,159,178,117,71,24,89,221,202,133,120,101,130,167,205,184,76,38,
		112,188,158,109,81,58,63,112,175,166,135,88,64,118,205,222,162,143,72,72,192,176,135,89,12,41,163,231,146,130,129,69,
		160,213,176,100,19,58,156,216,140,92,94,24,75,200,186,106,87,65,138,221,156,145,144,64,52,161,215,135,83,110,123,164,
		229,116,50,91,80,156,182,114,54,90,184,205,205,152,134,123,84,159,160,77,31,22,115,189,185,107,63,86,68,171,229,159,
		95,46,107,185,255,163,69,112,55,135,216,156,84,20,51,138,239,163,92,118,80,154,231,211,108,30,85,153,221,176,80,83,
		84,105,170,184,113,26,66,166,206,181,68,56,67,96,199,143,104,62,54,147,208,232,103,87,98,90,220,213,160,80,35,107,
		184,212,99,51,53,48,156,195,124,58,24,94,204,182,108,133,116,97,211,221,151,100,32,103,216,211,99,81,127,77,165,210,
		110,92,75,104,190,218,133,30,55,127,133,113,156,131,52,119,210,162,89,138,123,78,187,232,162,69,42,101,167,217,131,67,
		78,56,136,213,184,90,34,91,162,224,205,81,61,126,148,175,162,92,18,49,178,209,146,51,80,154,123,146,157,128,81,67,
		157,226,183,59,72,119,111,193,188,127,66,28,143,223,200,110,63,124,108,155,206,131,72,19,53,136,213,167,55,132,150,118,
		177,172,142,63,23,128,211,218,99,29,144,143,120,178,133,73,33,51,162,203,170,108,83,159,163,190,230,141,83,24,53,163,
		216,165,43,94,137,147,204,145,77,30,39,117,216,232,108,90,134,107,174,224,137,66,13,68,181,201,152,35,97,169,90,140,
		200,174,86,53,136,206,232,129,32,84,156,156,132,133,88,23,48,162,239,176,58,74,164,190,203,134,67,53,24,120,202,196,
		102,14,133,156,127,190,166,109,57,127,197,160,174,118,58,132,145,92,154,179,77,68,119,148,190,113,16,112,157,107,177,176,
		99,82,89,163,223,211,82,27,156,118,69,174,182,108,46,56,151,226,187,53,35,171,147,69,161,156,90,83,118,211,205,140,
		66,94,213,151,119,188,97,23,118,187,156,135,66,37,163,129,61,165,153,70,33,59,167,236,186,50,94,215,166,182,206,119,
		44,24,117,210,213,113,16,117,148,95,177,166,90,58,50,115,179,198,95,37,152,158,127,194,139,48,99,150,206,204,109,89,
		136,205,146,87,117,42,45,144,151,136,140,90,105,206,145,34,122,199,87,58,110,142,202,172,78,88,218,133,53,198,161,59,
		57,101,183,239,157,74,193,175,67,139,176,70,30,54,61,178,208,64,65,211,160,47,169,175,43,75,164,200,160,81,47,147,
		231,124,113,194,106,35,97,185,213,143,34,63,214,157,50,128,162,104,83,138,202,169,58,49,165,219,99,34,156,151,121,140,
		91,154,182,83,68,157,160,52,88,187,102,55,145,184,147,107,143,201,234,124,22,133,148,102,84,78,129,112,100,134,201,172,
		63,107,178,125,59,55,58,117,229,176,59,158,185,83,185,215,99,90,115,100,146,199,92,80,189,130,103,211,166,41,29,46,
		152,211,100,33,110,233,150,81,170,137,113,146,177,186,107,60,82,191,201,69,82,140,125,80,65,102,131,117,49,104,214,168,
		101,163,182,88,104,125,159,233,171,94,106,185,142,40,123,127,40,101,132,97,125,176,169,108,141,90,31,166,164,127,93,29,
		104,154,199,190,108,166,189,98,172,188,81,85,45,82,186,195,112,69,190,138,38,144,201,104,29,72,138,218,182,64,74,143,
		157,74,59,178,216,126,69,123,192,184,120,85,113,127,141,228,184,61,77,54,104,212,136,52,39,166,177,22,160,223,99,87,
		96,144,174,207,163,47,118,165,60,134,219,128,89,40,64,149,209,186,18,82,182,105,131,197,131,51,126,141,112,169,155,94,
		141,190,83,77,200,182,91,61,81,145,220,205,58,74,178,69,95,139,78,108,59,66,149,198,159,56,155,205,71,152,225,108,
		105,67,49,169,207,155,74,147,216,79,108,197,124,98,50,48,120,175,239,126,69,139,119,87,111,191,142,51,60,82,159,231,
		160,78,100,98,121,185,219,166,66,55,85,186,230,112,53,124,162,92,121,216,155,54,42,78,165,234,185,58,61,200,112,19,
		174,169,71,64,111,200,165,102,84,73,164,192,68,63,185,191,108,85,132,149,160,143,121,187,101,68,192,136,95,52,22,152,
		229,207,123,111,182,147,59,115,176,65,45,93,91,150,181,153,105,99,128,135,175,217,201,113,35,41,134,239,187,80,57,112,
		183,182,163,100,48,64,60,119,229,174,55,144,191,80,90,181,148,46,50,92,175,216,120,68,94,195,181,81,151,215,155,62,
		76,169,162,112,86,80,150,161,70,71,157,145,41,74,157,216,243,130,108,106,77,183,206,134,61,28,108,180,211,172,58,69,
		126,112,154,198,128,41,54,98,166,237,173,63,84,162,133,112,174,152,48,25,83,155,225,211,138,93,150,172,74,105,160,109,
		63,21,72,178,198,161,76,61,147,150,188,220,103,52,35,93,218,217,160,56,81,173,111,166,209,91,44,44,103,196,209,136,
		29,107,206,79,84,209,146,59,58,97,188,211,125,50,52,169,205,57,81,184,134,93,106,176,193,146,123,80,158,181,70,121,
		157,98,59,69,158,222,224,100,63,176,131,85,182,187,67,53,108,128,208,204,91,31,44,149,172,100,126,102,53,75,139,240,
		219,162,93,103,197,101,79,138,125,133,66,48,117,182,223,152,81,128,149,127,189,183,75,24,33,106,199,207,98,19,71,165,
		210,120,57,97,114,136,153,193,167,114,142,116,148,180,120,121,171,162,73,24,37,117,219,192,103,61,130,186,128,116,115,80,
		86,90,154,225,178,88,38,124,182,103,150,202,133,97,81,118,190,226,146,33,74,144,142,83,91,122,54,69,112,180,238,200,
		132,63,170,199,86,104,155,171,89,37,58,108,203,179,81,37,110,172,147,142,127,95,43,89,196,232,207,75,78,170,140,126,
		110,109,107,77,99,131,191,186,112,148,191,121,46,93,183,123,30,28,38,152,247,146,65,56,129,230,139,46,144,208,125,66,
		148,206,151,146,107,78,187,162,23,73,195,134,32,72,141,164,196,160,55,76,142,135,142,169,121,30,51,144,228,207,102,60,
		104,215,194,95,87,90,119,117,117,192,204,147,87,34,111,168,82,111,152,103,70,77,178,243,205,99,66,164,227,168,40,65,
		139,85,57,96,149,163,139,86,72,159,134,52,152,211,116,58,106,204,219,162,66,32,140,207,163,63,71,140,126,142,118,140,
		224,164,106,88,118,204,112,34,126,115,38,28,122,232,191,95,53,107,222,197,68,65,142,180,150,133,164,100,85,164,181,118,
		20,80,187,148,82,44,52,186,240,128,101,100,172,214,56,49,131,97,36,68,193,177,108,96,110,210,208,66,67,182,174,77,
		100,157,123,164,172,78,102,139,84,68,165,188,77,64,119,201,252,143,73,102,183,209,61,46,146,94,43,76,172,185,82,94,
		145,189,175,42,61,175,189,146,88,91,154,196,175,92,38,146,211,58,50,174,122,79,121,182,221,153,78,61,152,206,64,13,
		109,146,92,77,154,187,152,100,103,143,159,153,97,140,211,147,85,83,166,210,145,85,36,99,203,136,36,72,144,91,57,165,
		218,207,145,47,93,185,199,72,14,185,175,75,93,160,219,124,107,122,124,218,135,25,96,208,149,43,113,170,175,129,94,69,
		86,223,119,17,152,195,132,76,118,179,232,160,41,84,107,175,160,39,56,150,173,59,99,209,174,120,119,181,182,187,120,5,
		113,202,137,61,64,145,173,161,106,52,142,179,85,118,203,147,51,47,162,217,136,72,78,155,195,149,79,25,93,202,194,113,
		49,91,198,211,134,31,92,200,101,63,160,188,74,21,145,211,189,93,50,120,184,223,155,34,44,184,216,117,76,100,136,175,
		155,85,134,149,55,86,207,198,80,74,166,225,159,67,49,85,195,152,48,122,145,100,113,136,172,156,111,121,144,184,169,73,
		64,170,167,60,54,136,222,156,62,93,113,167,158,42,37,169,204,106,73,129,195,164,96,97,138,208,145,14,76,186,142,94,
		105,129,212,225,137,101,135,166,91,42,130,128,62,76,89,163,219,148,84,75,151,151,76,155,183,115,89,67,137,241,184,81,
		78,112,167,169,68,49,139,164,74,49,167,188,95,97,151,202,203,77,14,126,209,133,56,91,137,151,193,185,107,117,101,80,
		196,230,123,35,64,127,195,207,84,45,60,113,212,126,24,94,175,113,95,210,187,101,116,162,210,193,69,4,119,215,131,35,
		93,171,164,162,130,86,123,135,99,156,202,107,48,95,163,217,167,69,56,117,180,179,74,20,144,199,109,95,181,202,100,86,
		132,120,155,106,11,76,212,190,56,77,157,191,174,112,106,136,186,113,31,138,188,101,37,105,193,176,133,116,128,133,126,126,
		55,36,175,228,139,64,108,176,190,169,84,90,126,161,132,40,123,179,130,56,104,231,216,159,73,106,159,150,147,40,16,127,
		223,137,40,120,188,166,98,114,119,160,202,60,47,185,203,78,24,138,211,161,77,114,174,177,168,69,33,162,225,120,66,118,
		138,148,138,83,83,145,171,111,38,113,201,158,81,57,171,228,189,128,96,158,133,137,104,11,86,178,173,68,86,208,188,99,
		71,129,171,184,121,33,116,205,134,31,56,177,174,107,112,91,116,168,157,129,75,99,175,178,101,69,129,176,187,118,64,68,
		139,204,104,75,148,158,81,63,183,219,191,147,115,145,158,166,138,48,2,111,215,152,41,56,176,230,164,93,96,138,218,160,
		29,123,189,90,19,75,196,191,77,52,121,166,208,184,64,18,121,239,174,48,67,167,229,151,51,73,124,202,151,11,102,210,
		145,56,85,178,206,169,103,119,129,153,181,48,32,161,172,73,28,106,198,210,137,88,97,153,196,110,38,125,225,160,65,101,
		149,160,145,98,68,75,135,163,86,40,135,218,153,72,102,169,177,155,94,71,129,165,177,87,29,128,212,171,57,56,162,210,
		138,84,134,188,202,163,71,12,123,226,132,21,68,178,187,131,90,106,149,202,165,47,102,218,175,61,58,126,184,189,86,43,
		98,186,195,68,33,143,213,138,49,108,184,177,147,107,115,108,126,174,54,31,176,202,107,65,129,155,177,177,138,136,156,190,
		113,20,92,201,137,12,76,130,128,192,144,77,95,150,213,103,23,174,213,100,40,93,184,158,126,101,97,155,137,160,120,16,
		114,217,186,66,64,201,166,92,122,109,106,164,160,67,42,164,210,100,62,137,193,170,143,129,119,169,199,157,86,36,77,206,
		179,37,55,115,166,212,148,40,82,183,156,154,100,21,95,203,180,55,79,169,148,99,137,162,114,168,128,8,103,218,156,50,
		85,201,221,152,99,96,133,166,175,91,4,130,219,120,46,76,184,234,168,96,103,153,188,162,55,34,158,195,70,17,110,194,
		189,127,77,111,161,167,186,127,23,74,206,201,78,48,142,180,128,114,80,71,174,169,39,54,202,167,52,107,177,178,158,130,
		89,106,156,163,156,75,41,146,227,178,67,66,174,235,155,77,103,156,192,143,44,43,149,154,58,77,147,157,129,120,128,128,
		155,172,87,25,160,221,95,61,140,183,158,125,125,142,126,138,116,28,97,204,173,74,54,164,228,168,72,76,118,152,175,77,
		18,113,214,139,27,109,167,162,181,145,118,131,178,188,81,14,116,214,149,44,44,150,231,179,70,76,163,183,177,83,11,130,
		184,139,89,59,94,164,208,126,50,105,196,148,20,102,193,126,97,109,135,160,212,181,71,118,167,151,90,19,110,189,163,86,
		49,129,199,175,120,128,126,178,222,99,20,111,200,101,21,99,174,165,124,130,93,117,202,139,28,83,220,161,63,73,120,189,
		179,117,65,110,178,180,167,47,27,181,211,133,61,63,174,233,162,69,76,144,177,151,46,36,187,204,68,41,104,159,209,154,
		59,96,157,180,217,125,2,82,205,174,36,41,170,180,128,105,114,131,179,156,32,100,221,163,60,62,175,192,122,92,95,147,
		160,150,125,26,82,205,164,98,46,112,218,177,99,57,126,184,168,128,27,75,219,192,59,59,162,204,187,95,70,149,189,202,
		169,56,22,149,219,119,16,72,189,190,97,67,125,151,196,144,22,86,208,191,71,41,128,212,186,86,81,134,191,194,107,43,
		124,184,112,66,36,115,227,183,89,88,159,145,163,151,19,72,217,180,57,34,132,202,153,79,60,143,201,175,135,35,72,215,
		209,91,19,110,218,174,60,67,146,186,169,58,28,164,236,112,73,0,
	},
};

#undef STRUCT_NAME
#undef DATASIZE
#undef FMTC1
#undef FMTC0
#undef CHANS
#undef BITS
#undef SAMPLERATE
#undef FILESIZE
