#define CHUNKSIZE 80

typedef struct Chunk {
  char ch[CHUNKSIZE];
  struct Chunk *next;
} Chunk;

typedef struct LString {
  Chunk *head, *tail;
  int curlen;
} LString;