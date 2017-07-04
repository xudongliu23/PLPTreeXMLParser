#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "include/cicp_plptree_xml_parser.hxx"
#include "include/cicp_plptree.h"

using namespace std;

int main (int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Not enough arguments" << endl;
		return 1;
	}

	string plptree_xml_fullpath(argv[1]);

	CicpPlptree *tree = new CicpPlptree();
	if (buildPLPTreeFromXML(plptree_xml_fullpath, tree)) {
		cerr << "ERROR" << endl;
		exit(1);
	}
	displayPLPTree(tree);
	deletePLPTree(tree);

	return 0;
}
