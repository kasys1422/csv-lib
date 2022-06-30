//
// CSV読み込みヘッダーオンリーライブラリ(C++)
//
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ostream>
#include <string>

class LoadCSV {
private:
	//メンバ変数
	std::vector<std::vector<std::string>> csv_array;
	std::string path;
	std::ifstream input_file_stream;
	std::string buffer;
	char delimiter = ',';

	//プライベートメンバ関数
	//split関数(区切り文字で分割)
	std::vector<std::string> Split(std::string input, char delimiter)
	{
		int a = 0;
		int b = 0;
		std::vector<std::string> result;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == delimiter || i == input.size() - 1) {
				b = i;
				if (i == input.size() - 1 && result.size() != 0) {
					std::string buf = input.substr(a, b - a + 1);
					if (buf.size() >= 0) {
						if (buf[0] != delimiter)
							result.push_back(buf);
					}
				}
				else if (b - a >= 0) {
					result.push_back(input.substr(a, b - a));
				}
				a = i + 1;
			}
		}
		return result;
	}

public:

	//コンストラクタ
	LoadCSV(std::string path) {
		input_file_stream = std::ifstream(path);
	}
	//デストラクタ
	~LoadCSV() {

	}

	//パブリックメンバ関数
	//区切り文字指定
	void SetDelimiter(char value) {
		delimiter = value;
	}

	//ロード関数
	std::vector<std::vector<std::string>> Load() {
		//1行目だけ先に読み込み
		std::getline(input_file_stream, buffer);
		//BOMチェック
		if (buffer.size() > 3) {
			if (buffer[0] == 0xEF && buffer[1] == 0xBB && buffer[2] == 0xBF) {
				buffer.erase(0, 3);

			}
		}
		csv_array.push_back(Split(buffer, delimiter));
		while (std::getline(input_file_stream, buffer)) {
			csv_array.push_back(Split(buffer, delimiter));
		}

		return csv_array;
	}
};
