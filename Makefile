CXX = clang++
CPPFLAGS = -gdwarf-4

.PHONY: clean

all: application

application: event.o prepare.o arrival.o shipping.o eventNode.o eventPriorityQueue.o shipmentQueue.o shippingNode.o fileReader.o

clean:
	rm -f application event.o prepare.o arrival.o shipping.o eventNode.o eventPriorityQueue.o shipmentQueue.o shippingNode.o fileReader.o