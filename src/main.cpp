#include "Pool.h"

int main(int argc, char* argv[])
{
    engine::Pool<int, 256> pool;
    pool.activateObject();
    pool.deactivateObject(0);
	return 0;
}