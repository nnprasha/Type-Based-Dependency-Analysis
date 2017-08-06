@echo off
cd "Debug"
start CodeAnalyzer.exe ../FilesToTest/ *.h /xmlDep ../XmlResult/DepAnalResult.xml /xmlSc ../XmlResult/StrongComponent.xml