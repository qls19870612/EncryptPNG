#include <iostream>
#include "Files.h"
#include "Encrypt.h"

int main()
{
	// 输入密钥
	aes_key key = { 0 };
	//std::cout << "请输入16位密钥：" << std::endl;
	//std::cin.get((char *)&key[0], key.size());
	key = { 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6 };
	// 寻找所有png图片
	std::vector<std::string> pngfiles;
	auto all_files = path::walk(path::curdir());
	for (auto filename : all_files)
	{
		if (path::splitext(filename)[1] == ".png")
		{
			pngfiles.push_back(filename);
		}
	}

	// 取相对路径
	auto absolute_path = path::curdir() + "\\";
	for (auto &filename : pngfiles)
	{
		//filename = filename.substr(absolute_path.size(), filename.size());
	}

	std::cout << "正在加密中..." << absolute_path << std::endl;

	// 图片加密操作
	EncryptPNG(pngfiles, key);

	system("pause");

	return 0;
}