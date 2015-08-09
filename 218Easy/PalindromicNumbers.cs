using System;
using System.Linq;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Numerics;
using System.Threading.Tasks;

static class PalindromicNumbers
{
    public static string Reverse(string s)
    {
        char[] charArray = s.ToCharArray();
        int len = s.Length - 1;

        for (int i = 0; i < len; i++, len--)
        {
            charArray[i] ^= charArray[len];
            charArray[len] ^= charArray[i];
            charArray[i] ^= charArray[len];
        }

        return new string(charArray);
    }

	public static Tuple<BigInteger, int> GetPalindromicNumber(String n, int steps = 0)
	{
		BigInteger result = BigInteger.Parse(n);

		while (result.ToString() != Reverse(result.ToString())) 
		{
			BigInteger num = BigInteger.Parse(result.ToString());
			BigInteger reversed = BigInteger.Parse(Reverse(result.ToString()));

			result = num + reversed;

			if (steps < 500) 
				steps++;
			else 
			{
				// Return -1 to indicate this number is likely to never converge
				return Tuple.Create(BigInteger.MinusOne, steps);
			}
		}

		return Tuple.Create(result, steps);
	}

	public static SortedDictionary<BigInteger, ArrayList> RunBonus()
	{
		SortedDictionary<BigInteger, ArrayList> lookup = new SortedDictionary<BigInteger, ArrayList>();

		for (int number = 1; number <= 1000; number++) 
		{
			// Ignoring Item2 of this tuple because it is not needed.
			Tuple<BigInteger, int> tuple = GetPalindromicNumber(number.ToString());

			if (lookup.ContainsKey(tuple.Item1)) 
				lookup[tuple.Item1].Add(number);
			else 
			{
				lookup.Add(tuple.Item1, new ArrayList());
				lookup[tuple.Item1].Add(number);
			}
		}

		return lookup;
	}

	// Parallel version of the same function above.
	public static SortedDictionary<BigInteger, ArrayList> RunBonusParallel()
	{
		ConcurrentDictionary<BigInteger, ArrayList> lookup = new ConcurrentDictionary<BigInteger, ArrayList>();

		Parallel.For(1, 1000, (int number) =>
		{
			// Ignoring Item2 of this tuple because it is not needed.
			Tuple<BigInteger, int> tuple = GetPalindromicNumber(number.ToString());

			if (lookup.ContainsKey(tuple.Item1)) 
				lookup[tuple.Item1].Add(number);
			else 
			{
				lookup.TryAdd(tuple.Item1, new ArrayList());
				lookup[tuple.Item1].Add(number);
			}
		});

		return new SortedDictionary<BigInteger, ArrayList>(lookup);
	}

	public static void Main()
	{
		Console.WriteLine("Enter numbers: ");
		String input = Console.ReadLine();
		SortedDictionary<BigInteger, ArrayList> dict;
		String[] inputList = input.Split(' ');

		foreach (String number in inputList) 
		{
			int count = 0;
			Tuple<BigInteger, int> result = GetPalindromicNumber(number, count);
			count += result.Item2;

			Console.WriteLine(number + " gets palindromic after " + result.Item2 + " steps: " + result.Item1.ToString());
		}

		Stopwatch time = Stopwatch.StartNew();
		dict = RunBonusParallel();
		time.Stop();

		foreach (KeyValuePair<BigInteger, ArrayList> pair in dict) 
		{
			String elements = "";
			foreach (int elem in pair.Value) 
				elements += elem.ToString() + ", ";

			Console.WriteLine("{0}: {1}", pair.Key, elements);
		}

		Console.WriteLine("\nBonus ran in " + time.Elapsed.TotalMilliseconds + " ms.");
	}
}
