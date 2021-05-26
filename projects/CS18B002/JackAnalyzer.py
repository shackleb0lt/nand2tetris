#!/usr/bin/env python3
import sys
import os
import JackCompilationEngine
import JackCompilationEngineXML

def main():
    n=sys.argv[1]
    for i in range(2,int(n)+2):
        if len(sys.argv) < 2:
            print("Error. Missing argument: input (dir./file)")
            return -1

        if not os.path.exists(sys.argv[i]):
            print("Error:", sys.argv[1], "does not exist.")
            return -1
        isError=False
        xml_output = True
        #if len(sys.argv)>2:
        #   xml_output=True
        #else:
        input_file = sys.argv[i]
        compileFile(input_file, xml_output,isError)
        
def compileFile(input_path, xml_output=False,isError=False):
        if xml_output:
                print(input_path, "- Generating XML", "...")
                isError=JackCompilationEngineXML.JackCompilationEngineXML(input_path, replaceExtension(input_path, ".xml"),replaceExtension(input_path,".err"))
        errFile=open(replaceExtension(input_path,".err") ,'r' )
        if errFile.read()=="":
            print(input_path, "- Compiling", "...")
            JackCompilationEngine.JackCompilationEngine(input_path, replaceExtension(input_path, ".vm"))

def replaceExtension(input_name, extension):
    return input_name.replace(".jack", extension)

if __name__ == '__main__':
	main()
