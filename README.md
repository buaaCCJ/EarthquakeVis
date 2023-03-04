###  地震可视化项目
* 底图： arcgis


###  引擎
* unreal版本：5.1.1
* visual studio建议版本：vs2022
* Windows

### 步骤
1. 启动工程时，如提示缺少dll，请将\Plugins\VTKPlugin\Source\ThirdParty\VTK\Win64\dll下的所有dll拷贝至\EarthQuakeVis\Binaries\Win64下
2. 启动工程后，会默认在VTKDemo关卡
3. 在关卡大纲中，找到VTKLoader，然后下方指定下VTKFile所在的文件夹（不能含有中文），然后点击LoadAllVTKFile即可
![image](https://github.com/buaaCCJ/EarthquakeVis/blob/master/doc/%E6%AD%A5%E9%AA%A41.png)
