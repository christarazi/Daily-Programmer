Imports System.Collections
Imports System.Collections.Generic

Module PalindromicNumbers

    Function GetPalindromicNumber(ByVal n As String, ByRef steps As Integer) As Decimal
        Dim result As String = n

        Do While result <> StrReverse(result)
            Dim num As Decimal = Decimal.Parse(result)
            Dim reversed As Decimal = Decimal.Parse(StrReverse(result))

            result = num + reversed

            If steps < 500 Then
                steps = steps + 1
            Else
                Return Decimal.MinusOne
            End If
        Loop

        Return result
    End Function

    Sub RunBonus()
        Dim lookup as New Dictionary(Of Decimal, ArrayList)

        For number As Integer = 1 To 1000
            Dim key as Decimal = GetPalindromicNumber(number.ToString(), 0)

            If lookup.ContainsKey(key) Then
                lookup(key).Add(number)
            Else
                lookup.Add(key, New ArrayList)
                lookup(key).Add(number)
            End If
        Next

        Dim pair As KeyValuePair(Of Decimal, ArrayList)
        For Each pair In lookup
            Dim elements As String = ""
            For Each elem As Integer In pair.Value
                elements &= elem.ToString() & " "
            Next
            Console.WriteLine("{0}, {1}", pair.Key, elements)
        Next
    End Sub

    Sub Main()
        Console.WriteLine("Enter numbers: ")
        Dim input As String = Console.ReadLine()
        Dim inputList As Array
        inputList = input.Split(" ")

        For Each number As String In inputList

            Dim count As Integer = 0
            Dim result As Decimal = GetPalindromicNumber(number, count)

            Console.WriteLine(number & " gets palindromic after " & count & " steps: " & result)

            RunBonus()
        Next

    End Sub

End Module