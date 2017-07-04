# PLPTreeXMLParser

The C++ program parses an XML file that encodes a PLP-tree into memory.

## XML

The XML file that encodes a PLP-tree follows an XML schema.
For example, a CICP PLP-tree XML file follows the schema specified
in cicp_plptree_xml_parser.xsd.
Note schema file cicp_plptree_xml_parser.xsd is in the repo and it was
manually created for the CICP class of PLP-trees.

## PLP-tree in Memory

The C++ program reads a PLP-tree XML file and creates a PLP-tree structure
in memory for that XML file.

## How to use it?

### Compile
To compile the program, one needs to install 
* [CodeSynthesis XSD](http://www.codesynthesis.com/products/xsd/)
* [Xerces-C++ Library](https://xerces.apache.org/xerces-c/install-3.html)

Then execute command:
```
make
```


### Run

`./produce`*`path_to_XML`*

## Versioning

We use [github](https://github.com/) for versioning.

## Authors

* [Xudong Liu](https://www.unf.edu/~xudong.liu/)


## License

This project is currently not under any license.

## Acknowledgments

* Inspiration
* GitHub Flavored Markdown
* Doxygen
* etc
