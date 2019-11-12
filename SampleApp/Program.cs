using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            OpenFile("test.txt");
        }

        private static void OpenFile(string filePath)
        {
            using (FileStream fs = File.OpenRead(filePath))
            {
            }
        }
    }
}
