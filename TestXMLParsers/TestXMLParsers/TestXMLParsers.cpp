// TestXMLParsers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




#include "stdafx.h"
#define TIXML_USE_TICPP
//#define TIXML_USE_STL
#include <iostream>

#define BOOST_AUTO_TEST_MAIN
//#include <D:/RepoGIT/CGL/Libs/tinyxml/interface/tinystr.h>
//#include <D:/RepoGIT/CGL/Libs/tinyxml/interface/tinyxml.h>

#include "D:/RepoGIT/iMesh2/include/VtdReader/VTDXMLBuffer.h"
#include "D:/RepoGIT/iMesh2/include/VtdReader/VTDXMLReader.h"

#include "D:/SVN/tixml++/ticpp.h"
#include <boost/test/unit_test.hpp>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string> 

namespace
{
	const char xml1[] = "<root><item1></item1><item2></item2></root>";
	const char xml2[] = "<DS><CBasicElement><m_fileID>283689883</m_fileID><m_providerID>3</m_providerID><m_eMediaType>1</m_eMediaType><m_fileHash>851B406D02CFA2F1585990F1853527A1FBBAEF4C</m_fileHash><m_sFileName><![CDATA[10-SOS (Anything But Love).mp3]]></m_sFileName><m_sPath><![CDATA[D:\\!!!Music\\!!!new\\2007 - Worlds Collide]]></m_sPath><m_lFileSize>10506685</m_lFileSize><m_fileAttributes>32</m_fileAttributes><m_lastModifiedTime>128339066882343750</m_lastModifiedTime><m_locationType>1</m_locationType><m_mapTags><item><key>268435474</key><data><m_metadataTagID>268435474</m_metadataTagID><m_MetadataTagData>D7070000</m_MetadataTagData><m_MetadataTagString><![CDATA[]]></m_MetadataTagString></data></item><item><key>268435475</key><data><m_metadataTagID>268435475</m_metadataTagID><m_MetadataTagData>40010000</m_MetadataTagData><m_MetadataTagString><![CDATA[]]></m_MetadataTagString></data></item><item><key>268435476</key><data><m_metadataTagID>268435476</m_metadataTagID><m_MetadataTagData>06010000</m_MetadataTagData><m_MetadataTagString><![CDATA[]]></m_MetadataTagString></data></item><item><key>268435482</key><data><m_metadataTagID>268435482</m_metadataTagID><m_MetadataTagData>00000000</m_MetadataTagData><m_MetadataTagString><![CDATA[]]></m_MetadataTagString></data></item><item><key>268435495</key><data><m_metadataTagID>268435495</m_metadataTagID><m_MetadataTagData>00000000</m_MetadataTagData><m_MetadataTagString><![CDATA[]]></m_MetadataTagString></data></item><item><key>536870914</key><data><m_metadataTagID>536870914</m_metadataTagID><m_MetadataTagData></m_MetadataTagData><m_MetadataTagString><![CDATA[�O�.(Orchestral Version).]]></m_MetadataTagString></data></item><item><key>536870915</key><data><m_metadataTagID>536870915</m_metadataTagID><m_MetadataTagData></m_MetadataTagData><m_MetadataTagString><![CDATA[AAAA[]]></m_MetadataTagString></data></item><item><key>536870916</key><data><m_metadataTagID>536870916</m_metadataTagID><m_MetadataTagData></m_MetadataTagData><m_MetadataTagString><![CDATA[QWERTY[]]></m_MetadataTagString></data></item><item><key>536870924</key><data><m_metadataTagID>536870924</m_metadataTagID><m_MetadataTagData></m_MetadataTagData><m_MetadataTagString><![CDATA[TRY[]]></m_MetadataTagString></data></item></m_mapTags><m_nSourcesCount>0</m_nSourcesCount></CBasicElement><CLocalFunc><m_FileStatus>2</m_FileStatus><m_bIsShared>1</m_bIsShared><m_playCounter>5</m_playCounter><m_partsHashesUID>1610612767</m_partsHashesUID><m_bSent>1</m_bSent><m_LastPlayTime>0</m_LastPlayTime><m_DownloadTime>0</m_DownloadTime><m_DateAddedTime>1189758120</m_DateAddedTime><m_bIntVideo>0</m_bIntVideo><m_bID3DataStatus>1</m_bID3DataStatus></CLocalFunc><CMNFunc><m_MNExistingLicenseType>3</m_MNExistingLicenseType><m_MNNeededLicenseType>1</m_MNNeededLicenseType><m_DateLicenseRenewed>1189681763</m_DateLicenseRenewed><m_MNAcquireStatus>0</m_MNAcquireStatus><m_locationType_>3452816845</m_locationType_></CMNFunc></DS>";
	const char xml3[] = "<root><item1>sdfERTEsdf</item1><item1><![CDATA[QWERT]]YQWE</item1>RTY]]></item1><item2>Test</item2></root>";
	const char xml4[] = "<root><item1><![CDATA[QW]ERT]>YQWE</item1>RTY]]></item1><item2>Test</item2></root>";
	const char xml5[] = "<root><item1>data</item1>sfsdfs</item0><item2>Test</item2></root>";
	const char xml6[] = "<root><item1>data</item1>sfsdfs<item2><item0></item0>Test<item0></item0><item0></item0></item2></root>";
	const char xml7[] = "<root><item2><![CDATA[QWERT]]>YQWE]]></item2><item2>Test</item2></root>";
	const char xml8[] = "<root><item2><![CDATA[</item1>]]></item2><item1>Test</item1></root>";
	const char xml9[] = "<root><item1>Test</item1><item2><![CDATA[QWERT]]></item0>]]></item2></root>";
}
const unsigned int NUM_INDENTS_PER_SPACE=2;

const char * getIndent( unsigned int numIndents )
{
	static const char * pINDENT="                                      + ";
	static const unsigned int LENGTH=strlen( pINDENT );
	unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH ) n = LENGTH;

	return &pINDENT[ LENGTH-n ];
}

// same as getIndent but no "+" at the end
const char * getIndentAlt( unsigned int numIndents )
{
	static const char * pINDENT="                                        ";
	static const unsigned int LENGTH=strlen( pINDENT );
	unsigned int n=numIndents*NUM_INDENTS_PER_SPACE;
	if ( n > LENGTH ) n = LENGTH;

	return &pINDENT[ LENGTH-n ];
}

int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent, std::ofstream& outFile)
{
	if ( !pElement ) return 0;

	TiXmlAttribute* pAttrib=pElement->FirstAttribute();
	int i=0;
	int ival;
	double dval;
	const char* pIndent=getIndent(indent);
	//outFile << "\n";
	while (pAttrib)
	{
		outFile << pIndent << pAttrib->Name()<< "value=["<< pAttrib->Value()<<"]";

		if (pAttrib->QueryIntValue(&ival)==TIXML_SUCCESS)    outFile <<  " int="<<  ival;
		if (pAttrib->QueryDoubleValue(&dval)==TIXML_SUCCESS) outFile << " d= "<< dval;
		//outFile <<  "\n" ;
		i++;
		pAttrib=pAttrib->Next();
	}
	return i;	
}

void dump_to_stdout( TiXmlNode* pParent, std::ofstream& outFile, unsigned int indent = 0 )
{
	if ( !pParent ) return;
	

	TiXmlNode* pChild;
	TiXmlText* pText;
	int t = pParent->Type();
	outFile << getIndent(indent);
	int num;

	switch ( t )
	{
	case TiXmlNode::DOCUMENT:
		outFile << "Document" ;
		break;

	case TiXmlNode::ELEMENT:
		outFile << "Element [" << pParent->Value() << "]";
		num=dump_attribs_to_stdout(pParent->ToElement(), indent+1, outFile);
		//switch(num)
		//{
		//case 0:  outFile <<  " (No attributes)"; break;
		//case 1:  outFile <<  getIndentAlt(indent)<<"1 attribute"; break;
		//default: outFile <<  getIndentAlt(indent)<< num<<" attributes"; break;
		//}
		break;

	case TiXmlNode::COMMENT:
		outFile <<  "Comment: ["<< pParent->Value()<<"s]";
		break;

	case TiXmlNode::UNKNOWN:
		outFile <<  "Unknown" ;
		break;

	case TiXmlNode::TEXT:
		pText = pParent->ToText();
		outFile <<  "Text: [" << pText->Value() <<"]";
		break;

	case TiXmlNode::DECLARATION:
		outFile <<  "Declaration";
		break;
	default:
		break;
	}
	outFile<< "\n" ;
	for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
	{
		dump_to_stdout( pChild, outFile, indent+1 );
	}
}

void dump_to_stdout1(const char* pFilename, int numberFile)
{
	long long val(numberFile);
	std::string path(std::to_string(val) );
	std::ofstream outFile(path);
	TiXmlDocument doc(pFilename);
	bool loadOkay = doc.LoadFile();
	if (loadOkay)
	{
		printf("\n%s:\n", pFilename);
		dump_to_stdout( &doc, outFile ); // defined later in the tutorial
	}
	else
	{
		printf("Failed to load file \"%s\"\n", pFilename);
	}
	outFile.close();
}

void TestTinyProcess(const std::string& str, const char* result = NULL, bool correct = true)
{
	static int i = 0;
	++i;
	srand(time(0));
	double starttime =  clock()/1000.0;
	std::cout << "strattime = " << clock()/1000.0 << std::endl;
	TiXmlDocument doc;//("Default.xml");
	bool loadOkay = doc.LoadFile("Default.xml");
	std::cout << "endTime = " << clock()/1000.0 -starttime << std::endl<< std::endl;
	if (!loadOkay)
	{
		printf("Failed to load file \"%s\"\n", "default.xml");
	}
	else
	{
		dump_to_stdout1("default.xml", i);
	}
	
	//TiXmlDocument doc;
	//doc.Parse(str.c_str());
	//std::string path = doc.Parse("default.xml");

	bool err = doc.Error();

	bool res = !((0 == err) ^ correct);
	if (!res)
	{
		std::cout << "xml " << i << ": - error parse process" << std::endl;
		BOOST_CHECK( res );
	}

	if (err == 0 && result != NULL)
	{
		TiXmlElement *root = doc.RootElement();

		res = root != 0;

		if (res)
		{
			TiXmlElement* child = root->FirstChildElement("bubbles");
			res = child != 0;
			if(res)
			{
				const char* text = child->GetText();

				std::string resData = text != NULL? text: "";

				bool check = resData == result;
				if (!check)
				{
					std::cout << "xml " << i << ": - wrong data(" << resData.c_str() << ")" << std::endl;
					BOOST_CHECK( check );
				}
			}
		}

		if (!res)
		{
			std::cout << "xml " << i << ": - item2 not found" << std::endl;
			BOOST_CHECK( res );
		}
	}
	
}
void TestTinyProcessCPP(const std::string& str, const char* result = NULL, bool correct = true)
{
	static int i = 0;
	++i;
	
	
	try
	{
		srand(time(0));
		double starttime =  clock()/1000.0;
		std::cout << "strattime = " << clock()/1000.0 << std::endl;
		ticpp::Document doc;
		doc.LoadFile("Default.xml");
		std::cout << "endTime = " << clock()/1000.0 - starttime<< std::endl<< std::endl;
		ticpp::Element* pElem = doc.FirstChildElement();
		dump_to_stdout1("default.xml", i);
	}
	catch( ticpp::Exception& ex )
	{
		std::cout << ex.what();
	}
	
}

void TestVTDProcess(const std::string& str, const char* result = NULL, bool correct = true)
{
	static int i = 0;
	++i;

	VTDXml::VTDXMLBuffer buffer(str);
	VTDXml::VTDXMLReader vtdReader;

	srand(time(0));
	std::cout << "startTime = " << clock()/1000.0 << std::endl;

	bool err = vtdReader.Parse(&buffer);
	std::cout << "endTime = " << clock()/1000.0 << std::endl;

	bool res = !(err ^ correct);

	if (!res)
	{
		std::cout << "xml " << i << ": - error parse process" << std::endl;
		BOOST_CHECK( res );
	}

	if (err && result != NULL)
	{
		res = vtdReader.ToElement(VTDXml::VTDXMLReader::directionRoot);
		BOOST_CHECK(res);

		if (res)
		{
			res = vtdReader.ToElement(VTDXml::VTDXMLReader::directionFirstChild, "item2"); 

			if(res)
			{
				std::string resData = vtdReader.GetValueA();

				bool check = resData == result;
				if (!check)
				{
					std::cout << "xml " << i << ": - wrong data(" << resData.c_str() << ")" << std::endl;
					BOOST_CHECK( check );
				}
			}
		}

		if (!res)
		{
			std::cout << "xml " << i << ": - item2 not found" << std::endl;
			BOOST_CHECK( res );
		}
	}
}

// int _tmain(int argc, _TCHAR* argv[])
// {
// 	return 0;
// }

BOOST_AUTO_TEST_CASE(TinyParser)
{
	//TestTinyProcess(xml1, "");
//	TestTinyProcess(xml2);
	TestTinyProcessCPP(xml3, "Test");
 	TestTinyProcess(xml3, "Test");
// 	TestTinyProcess(xml4, "Test");
// 	TestTinyProcess(xml5, NULL , false);
// 	TestTinyProcess(xml6, "");
// 	TestTinyProcess(xml7, "QWERT"); // This is different with VTD parser
// 	TestTinyProcess(xml8, "</item1>");
// 	TestTinyProcess(xml9, NULL, false);
}

BOOST_AUTO_TEST_CASE(VTDParser)
{
	TestVTDProcess(xml1, "");
	TestVTDProcess(xml2);
	TestVTDProcess(xml3, "Test");
	TestVTDProcess(xml4, "Test");
	TestVTDProcess(xml5, NULL , false);
	TestVTDProcess(xml6, "");
	TestVTDProcess(xml7, NULL, false); // This is different with tinyxml parser
	TestVTDProcess(xml8, "</item1>");
	TestVTDProcess(xml9, NULL, false);
}