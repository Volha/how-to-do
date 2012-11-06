// Composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "FileItem.h"
#include "FolderItem.h"


typedef std::shared_ptr<FolderItem> FolderItemPtr; 
typedef std::shared_ptr<FileItem> FileItemPtr; 

FolderItemPtr CreateFileSystem()
{
	FolderItemPtr root = std::make_shared<FolderItem>("Root");
	FolderItemPtr folder1 = std::make_shared<FolderItem>("Folder1");
	FolderItemPtr folder2 = std::make_shared<FolderItem>("Folder2");
	FileItemPtr file1 = std::make_shared<FileItem>("file1");
	FileItemPtr file2 = std::make_shared<FileItem>("file2");
	FileItemPtr file3 = std::make_shared<FileItem>("file3");

	root->AddItem(folder1);
	root->AddItem(file1);
	
	folder2->AddItem(file2);
	folder2->AddItem(file3);

	root->AddItem(folder2);
	return root;
};

std::string Findword(const std::string fullFilePath, size_t& begin)
{
	std::string subPath;
	size_t buf = 0;
	for (size_t i = begin; i < fullFilePath.size(); ++i)
	{
		if (fullFilePath[i] != '/')
		{
			subPath.push_back(fullFilePath[i]);
			buf = i; 
		} 
		else 
		{
			break;
		}
	}
	begin = ++buf;
	return subPath;
};

int main()
{
	FolderItemPtr root = CreateFileSystem(); 
	auto file = root->Find("Folder2/file2");
	return 0;
}