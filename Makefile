SHELL := /bin/bash

ifeq ($(shell uname),Darwin) #if using a Mac
  XSD_INCLUDE_FLAG:=-I/usr/local/opt/xsd-4.0.0-i686-macosx/libxsd
  ifeq ($(shell hostname -s),Xudongs-MacBook-Pro) #if using my MBP laptop
  USER_DIR:=/Users/xudong
  else ifeq ($(shell hostname -s),CIS-3211-64950)  #if using my office desktop
  USER_DIR:=/Users/n01237497
  else
  USER_DIR:=
  endif
else #if using my Linux laptop
  XSD_INCLUDE_FLAG:=-I$(USER_DIR)/Downloads/xsd-4.0.0-x86_64-linux-gnu/libxsd
  USER_DIR:=/home/xudong
endif


all: main clean

main: main.o cicp_plptree.o cicp_plptree_xml_parser.o
	g++ -w -std=c++11 -o main main.o cicp_plptree.o cicp_plptree_xml_parser.o -lxerces-c

main.o: main.cpp cicp_plptree.h cicp_plptree_xml_parser.hxx
	g++ -w -std=c++11 $(XSD_INCLUDE_FLAG) -c main.cpp

cicp_plptree.o: cicp_plptree.h cicp_plptree_xml_parser.hxx
	g++ -w -std=c++11 $(XSD_INCLUDE_FLAG) -c cicp_plptree.cpp

cicp_plptree_xml_parser.o: cicp_plptree_xml_parser.hxx
	g++ -w -std=c++11 $(XSD_INCLUDE_FLAG) -c cicp_plptree_xml_parser.cxx

clean:
	rm *.o
