#include "cicp_plptree.h"
#include "cicp_plptree_xml_parser.hxx"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /* for memcpy */


int buildPLPTreeFromXML(const string plptree_xml_path, CicpPlptree *plptree)
{
	try {
		auto_ptr<child_t> plpt (child (plptree_xml_path));
		buildPLPTreeFromXMLRecur(plpt.get(), plptree, 0, NULL);
	} catch(const xml_schema::exception& e) {
		cerr << e << endl;
		return 1;
	}

	return 0;
}

void buildPLPTreeFromXMLRecur(child_t *child, CicpPlptree *curNode, 
	int level, CicpPlptree *parNode) {
	curNode->level = level;

	if (child->attribute().present()) {
		curNode->name = child->attribute().get();
	}
	cout << child->attribute() << endl;

	child_t::preference_sequence& ps (child->preference());
	child_t::preference_iterator I (ps.end());
	I--;
	for (child_t::preference_iterator i (ps.begin ()); i != ps.end (); ++i) {
		cout << *i << endl;
		size_t colon_ind = (*i).find(":");
		curNode->pref.push_back((*i).substr(0,colon_ind));
		if (i == I) {
			curNode->pref.push_back((*i).substr(colon_ind+1));
		}
	}

	if (!parNode) { // curNode is root
      curNode->pathIssNames.push_back(curNode->name);
  } else {        // curNode is not root
      curNode->pathIssNames = parNode->pathIssNames;
      curNode->pathIssNames.push_back(curNode->name);
  }

	child_t::child_sequence& cs (child->child());
	for (child_t::child_iterator i (cs.begin ()); i != cs.end (); ++i) {
		CicpPlptree *treeNode  = new CicpPlptree();
		curNode->subtrees.push_back(treeNode);

		child_t ct (*i);
		buildPLPTreeFromXMLRecur(&ct, treeNode, level+1, curNode);
	}
}

void displayPLPTree(CicpPlptree *head)
{
    if (head->subtrees.size() == 0 || head->name == "") {
        cout << "Empty" << endl;
        cout << "Path issue names: ";
        for (auto& pathIssName : head->pathIssNames)
            cout << pathIssName << " ";
        cout << endl;
        return;
    }

    cout << head->level << ". ";
    cout << head->name << ": ";
    for (int i=0; i<head->pref.size(); i++) {
        cout << head->pref.at(i) << " ";
    }
    cout << endl;

    for (int i=0; i<head->subtrees.size(); i++)
        displayPLPTree(head->subtrees[i]);
}

void deletePLPTree(CicpPlptree *tree)
{
    if (tree->subtrees.size() == 0 || tree->name == "")
        return;

    for (int i=0; i<tree->subtrees.size(); ++i)
        deletePLPTree(tree->subtrees[i]);

    delete tree;
}
