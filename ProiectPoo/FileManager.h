#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class FileManager
{
public:	
	virtual void ReadFile()=0;
	//virtual void WriteFile() = 0;
};