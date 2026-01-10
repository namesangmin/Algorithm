using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project2
{
    class func
    {
        private int firstNum;
        private int secondNum;
        public func() { }
        public bool isZero()
        {
            if (firstNum == 0 && secondNum == 0) return true;
            return false;
        }
        public void inputNum(int First, int Second)
        {
            firstNum = First;
            secondNum = Second;
        }
        public string returnResult()
        {
            if (firstNum > secondNum) return "Yes";
            return "No";
        }
    }
    internal class Class1
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string[] input = Console.ReadLine().Split(' ');

                func f = new func();

                int tmFristNum, tmSecondNum;
                tmFristNum = Int32.Parse(input[0]);
                tmSecondNum = Int32.Parse(input[1]);
                f.inputNum(tmFristNum, tmSecondNum);
                if (f.isZero() == true) break;
                Console.WriteLine(f.returnResult());
            }
        }
    }
}
