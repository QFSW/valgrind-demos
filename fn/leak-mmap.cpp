#include <sys/mman.h>

int main()
{
    int bytes = 10000;
    void* mem = mmap(0, bytes, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);

    return 0;
}