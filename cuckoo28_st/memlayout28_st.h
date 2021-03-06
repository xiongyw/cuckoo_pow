#define HALFSIZE 0x8000000
#define LOGHALFSIZE 27
#define EDGEMASK (HALFSIZE - 1)
#define NODEMASK (HALFSIZE - 1)
#define NONCEMASK (2*HALFSIZE - 1)
#define NONCEMASKE (2*HALFSIZE - 2)
#define HALFCYCLELENGTH 21

//B0_SLOTS divisible by 64 to make CK_BIG1 aligned by 64
#define B0_SLOTS 528320
#define B1_SLOTS 334272
#define B2_SLOTS 157248
#define B3_SLOTS 94016
#define BR_SLOTS 64256
#define BP_SLOTS 64256
#define PAIRSLIST_PT 262144
#define PI_SLOTS_2 262144
#define PI_SLOTS_3 10240
#define PI_SLOTS_4 512
#define PI_SLOTS_5 64
#define PI_SLOTS_6 32
//557568 dwords
#define PI_SIZE 2230336

#define B_BUCKETS 256UL
#define B_LOG 8
#define B_BUCKETMASK (B_BUCKETS - 1)
#define B0_SLOTSIZE 5
#define B1_SLOTSIZE 5
#define B2_SLOTSIZE 5
#define B3_SLOTSIZE 5
#define BR_SLOTSIZE 6
#define BP_SLOTSIZE 4
#define B_SLOTPAYLOADSHIFT (LOGHALFSIZE-B_LOG)

#define S_BUCKETS 256
#define S_LOG 8
#define S_BUCKETMASK (S_BUCKETS - 1)
#define S0_SLOTS 2304
#define S1_SLOTS 1536
#define SR_SLOTS 1280
#define S0_SLOTSIZE 5
#define S1_SLOTSIZE 5
#define SR_SLOTSIZE 6

#define R_ENTRIES 2048
#define R_LOG 11

#define PTS0_SIZE (R_ENTRIES + S_BUCKETS * (S0_SLOTS * S0_SLOTSIZE + 4))
#define PTS1_SIZE (R_ENTRIES + S_BUCKETS * (S1_SLOTS * S1_SLOTSIZE + 4))
#define PAIRSLIST_SIZE 262144
#define EDGE1MAX 84860000

#define CK_SIPSTATE 4032
#define CK_SOLPTR 4072
#define CK_PAIRSCOUNT 4080
#define CK_ABORT 4092

#define CK_BIG0HEAD 4096UL
#define CK_BIG0BODY (CK_BIG0HEAD + B_BUCKETS * 4)
#define CK_EDGE1 CK_BIG0BODY
#define CK_BIG1 (CK_BIG0BODY + 65536*4 + EDGE1MAX * 4)
#define CK_BIG2 (CK_BIG1 + B_BUCKETS * (B1_SLOTS * B1_SLOTSIZE + 4) + 65536)
#define CK_BIG3 CK_BIG1
#define CK_PTS1 (CK_BIG2 + B_BUCKETS * (B2_SLOTS * B2_SLOTSIZE + 4) + 65536)
#define CK_PTS0 (CK_BIG0BODY + B_BUCKETS * B0_SLOTS * B0_SLOTSIZE)
#define CK_PAIRSLIST CK_BIG1
#define CK_PAIRSBITFIELD (CK_PAIRSLIST + PAIRSLIST_SIZE*12)
#define CK_PAIRSINDEX (CK_PAIRSBITFIELD + PAIRSLIST_SIZE/8)
#define CK_CYCLEBUF (CK_PAIRSINDEX + PI_SIZE)
#define CK_JUNCTIONS (CK_CYCLEBUF + 4096)
#define CK_BIGP CK_BIG2
#define CK_RENAMELIST (CK_BIG2 - 33554432)
#if ((CK_BIG3 + B_BUCKETS * (B3_SLOTS * B3_SLOTSIZE + 4)) > CK_RENAMELIST)
    #error "B3_SLOTS too big"
#endif

#define CK_CONTEXT_SIZE (CK_PTS1 + PTS1_SIZE)
