FROM debian:latest
RUN apt-get update && apt-get install -y valgrind gcc
WORKDIR ./app
COPY . /app
CMD ["bash"]