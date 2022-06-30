# include <Siv3D.hpp> // OpenSiv3D v0.6.4
# include "../../csv-lib.h"
void Main()
{
	ListBoxState ls1;
	ListBoxState ls2;
	Array<Array<String>> array2d;
	bool flag = false;
	while (System::Update())
	{
		if (SimpleGUI::Button(U"Choose file", Vec2{ 600, 20 }))
		{
			Optional<FilePath> path = Dialog::OpenFile({ { U"csv file",{ U"csv" } } });
			if (path != none) {
				LoadCSV csv = LoadCSV(path.value().toUTF8());
				Array list = csv.Load();
				Array<String> list_buffer;
				for (int i = 0; i < list.size(); i++) {
					String buffer;
					Array<String> array2d_buffer;
					for (int j = 0; j < list[i].size(); j++) {
						buffer.append(Unicode::Widen(list[i][j]));
						array2d_buffer << Unicode::Widen(list[i][j]);
						if (j != list[i].size() - 1)buffer << U'/';
					}
					list_buffer << buffer;
					array2d << array2d_buffer;
				}
				ls1 = ListBoxState(list_buffer);
				flag = true;
			}
		}
		if (flag == true)
		{
			if (SimpleGUI::ListBox(ls1, Vec2{ 20, 20 }, 560, 360) && ls1.selectedItemIndex)
			{
				ls2 = ListBoxState(array2d[ls1.selectedItemIndex.value()]);
			}
			if (SimpleGUI::ListBox(ls2, Vec2{ 20, 380 }, 560, 200) && ls2.selectedItemIndex)
			{
			}
		}
		if (SimpleGUI::Button(U"license", Vec2{ 600, 60 }))
		{
			LicenseManager::ShowInBrowser();
		}
	}
}
