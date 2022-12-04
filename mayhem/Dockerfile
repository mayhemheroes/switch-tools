FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential automake pkg-config libtool liblz4-dev libz-dev

COPY . /repo
WORKDIR /repo
RUN ./autogen.sh
RUN ./configure --prefix=/install
RUN make -j8
RUN make install

FROM ubuntu:20.04 as package
COPY --from=builder /install /install
COPY --from=builder /repo/elf2nro /
