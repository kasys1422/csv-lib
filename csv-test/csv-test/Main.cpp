# include <Siv3D.hpp> // OpenSiv3D v0.6.4
# include "../../csv-lib.h"
void Main()
{
	while (System::Update())
	{
		//ファイル選択
		if (SimpleGUI::Button(U"Choose file", Vec2{ 600, 0 }))
		{
			Optional<FilePath> path = Dialog::OpenFile({ FileFilter::AllFiles() });
			if (path == none)break;
			LoadCSV csv = LoadCSV(path.value().toUTF8());
			Array list = csv.Load();
			Print << U"[RESULT]------------------------------------------------------";
			for (int i = 0; i < list.size(); i++) {
				String buffer;
				for (int j = 0; j < list[i].size(); j++) {
					buffer.append(Unicode::Widen(list[i][j]));
					if (j != list[i].size() - 1)buffer<<U'/';
				}
				Print << buffer;
			}
		}
	}
}
