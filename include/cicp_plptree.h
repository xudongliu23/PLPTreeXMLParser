#ifndef PLPTREE_H
#define PLPTREE_H

#include <vector>
#include <string>
#include <utility>
#include <set>
#include "cicp_plptree_xml_parser.hxx"
using namespace std;

typedef vector<string>     vs;
typedef vector<int>        vi;
typedef set<string>        ss;

typedef pair<vs,string>    pVsS;
typedef vector<pVsS>      vpVsS;

typedef pair<string,vi>    pSVi;
typedef vector<pSVi>       vpSVi;

typedef struct CicpPlptree{
    int                    level;  /* start from 0 */
    string                 name;
    vs                pref;
    vs                pathIssNames;  /* names of all nodes in the path till, including, this node */
    vector<CicpPlptree*>  subtrees;
} CicpPlptree;

int buildPLPTreeFromXML(const string plptree_xml_path, CicpPlptree *plptree);
void buildPLPTreeFromXMLRecur(child_t *child, CicpPlptree *curNode, 
	int level, CicpPlptree *parNode);
void displayPLPTree(CicpPlptree *head);
void deletePLPTree(CicpPlptree *head);


#endif
