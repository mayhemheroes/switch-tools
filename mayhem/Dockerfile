FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential automake pkg-config libtool liblz4-dev libz-dev clang

COPY . /repo
WORKDIR /repo
RUN ./autogen.sh
RUN ./configure --prefix=/install
RUN make -j8
RUN make install

WORKDIR /repo/src
RUN clang++ /repo/mayhem/fuzz_local_bswap64.cpp -fsanitize=fuzzer,address -o /fuzz -I /repo/src

FROM ubuntu:22.04 as package
COPY --from=builder /install /install
COPY --from=builder /repo/elf2nro /
COPY --from=builder /fuzz /fuzz_local_bswap64
