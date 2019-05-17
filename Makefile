include Makefile.conf

check_folder:
	@if [ -d "build" ]; then echo "[!] Found previous build, use make clean to delete old artifacts" && exit 1; fi

clean:
	@echo "[*] Using sudo to delete old build files"
	sudo rm -rf build

build_base:
	@echo "[*] Building base image"
	docker build -q -t base -f docker/base.Dockerfile .

njs: check_folder build_base
	@echo "[*] Building njs images"
	docker build -q \
		-t njs \
		--build-arg ver=$(NJS_VERSION) \
		-f docker/njs.Dockerfile .
	docker run \
		--rm \
		-v `pwd`:/home/build/fluff \
		njs \
		./fluff/docker/scripts/build_njs.sh

duktape: check_folder build_base
	@echo "[*] Building duktape images"
	docker build -q \
		-t duktape \
		--build-arg url=$(DUKTAPE_URL) \
		-f docker/duktape.Dockerfile .
	docker run \
		--rm \
		-v `pwd`:/home/build/fluff \
		duktape \
		./fluff/docker/scripts/build_duktape.sh

jerryscript: check_folder build_base
	@echo "[*] Building jerryscript images"
	docker build -q \
		-t jerryscript \
		--build-arg ver=$(JERRYSCRIPT_VERSION) \
		-f docker/jerryscript.Dockerfile .
	docker run \
		--rm \
		-v `pwd`:/home/build/fluff \
		jerryscript \
		./fluff/docker/scripts/build_jerryscript.sh

v8: check_folder build_base
	@echo "[*] Building v8 images"
	docker build -q \
		-t v8 \
		--build-arg ver=$(V8_VERSION) \
		-f docker/v8.Dockerfile .
	docker run \
		--rm \
		-v `pwd`:/home/build/fluff \
		v8 \
		./fluff/docker/scripts/build_v8.sh

