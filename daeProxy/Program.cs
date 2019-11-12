using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace daeProxy
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = Path.GetDirectoryName(typeof(Program).Assembly.Location);
            ProcessStartInfo psi = new ProcessStartInfo();
            string dllPath = Path.Combine(path, "DebugAtException.dll");

            if (args.Length == 0)
            {
                Console.WriteLine("How to use:");
                Console.WriteLine("\tdaeProxy [target_exe_path]");
                Console.WriteLine();
                Console.WriteLine("\tor");
                Console.WriteLine();
                Console.WriteLine("\tSET COR_ENABLE_PROFILING=1");
                Console.WriteLine("\tSET COR_PROFILER={9aa43723-a2fd-4886-ba0c-ab1897214dc6}");
                Console.WriteLine("\tSET COR_PROFILER_PATH=" + dllPath);
                Console.WriteLine("\tthen run target executable.");
                return;
            }

            string targetPath = args[0];
            string targetFolder = Path.GetDirectoryName(targetPath);

            psi.FileName = targetPath;
            psi.WorkingDirectory = targetFolder;
            psi.UseShellExecute = false;

            psi.Environment.Add("COR_ENABLE_PROFILING", "1");
            psi.Environment.Add("COR_PROFILER", "{9aa43723-a2fd-4886-ba0c-ab1897214dc6}");
            psi.Environment.Add("COMPLUS_ZapDisable", "1");
            psi.Environment.Add("COR_PROFILER_PATH", dllPath);

            Process child = Process.Start(psi);
            child.WaitForExit();            
        }
    }
}
