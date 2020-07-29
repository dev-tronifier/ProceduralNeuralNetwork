#include "../include/init_file.h"

int main() {
	read_mnist("training/t10k-images.idx3-ubyte");
	read_mnist("training/train-images.idx3-ubyte");
	return 0;
}
