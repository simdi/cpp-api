FROM gcc:7.3.0

# Update the list of packages quietly and assumes 'yes' to all update promotes with -qq.
RUN apt-get -qq update
# Install the packages that are out of date quietly and assumes 'yes' to all update promotes with -qq.
RUN apt-get -qq upgrade
# Install cmake. for more verbose output use -y.
RUN apt-get -qq install cmake

RUN apt-get -qq install libboost-all-dev=1.62.0.1
RUN apt-get -qq install build-essential libtcmalloc-minimal4 && \
  ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so