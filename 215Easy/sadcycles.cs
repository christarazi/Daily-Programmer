/*
http://www.reddit.com/r/dailyprogrammer/comments/36cyxf/20150518_challenge_215_easy_sad_cycles/
*/

using System;
using System.Collections.Generic;
using System.Linq;

public class SadCycles
{
	public static void Main()
	{
		List<long> l = new List<long>();
		
		Console.Write("Enter base: ");
		long baseNum = long.Parse(Console.ReadLine());
		Console.Write("Enter starting number: ");
		string n = Console.ReadLine();

		long sum = 0;
		while (true)
		{
			foreach (char digit in n)
			{
				long temp = digit - '0';
				sum += (long) Math.Pow(temp, baseNum);
			}


			if (l.Where(x => x.Equals(sum)).Count() == 2) break;
			if (sum == 1) break;

			l.Add(sum);
			n = sum.ToString();
			sum = 0;
		}

		List<long> sadCycle = new List<long>();
		foreach (long i in l) 
		{
			if (l.Where(x => x.Equals(i)).Count() > 1) sadCycle.Add(i);
		}

		var sadCycleDistinct = sadCycle.Distinct().ToArray();
		Console.WriteLine("\nSad cycle:\n[" + string.Join(", ", sadCycleDistinct) + "]");
		Console.Write("\nLength of sad cycle: " + sadCycleDistinct.Count() + "\n");
	}
}