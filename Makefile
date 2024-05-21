.PHONY: build clean

BUILD_DIR := build

all: build

build:
	cmake -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug
	make -C $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*
