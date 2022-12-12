import os

def main():
    print("Creating a C# project. BE SURE THAT SKELETON IS ON DOWNLOAD DIRECTORY")
    name = input("Enter the name of the project : ")
    os.system("dotnet new console --language C# --name " + name)
    os.chdir(name)
    os.system("dotnet new sln --name " + name)
    os.system("mkdir " + name)
    os.system("mv *.csproj " + name)
    os.system("dotnet sln add " + name + "/" + name + ".csproj")
    os.system("mv Program.cs " + name)
    os.system("mv obj " + name)
    os.system("cp ~/Downloads/*.zip " + name + "/skeleton.zip")
    os.system("cp ~/afs/Epita-XFCE4-Config/cs_gitignore .gitignore")
    os.system("touch README")
    os.chdir(name)
    os.system("unzip skeleton.zip -d ../")
    os.system("rm skeleton.zip")


if __name__ == "__main__":
    main()
