Module PalindromicNumbers

    Sub Main()
        Console.WriteLine("Enter numbers: ")
        Dim input As String = Console.ReadLine()
        Dim inputList As Array
        inputList = input.Split(" ")

        For Each number As String In inputList

            Dim count As Integer = 0
            Dim result As String = number

            Do While result.ToString() <> StrReverse(result.ToString())
                Dim num As Decimal = Decimal.Parse(result)
                Dim reversed As Decimal = Decimal.Parse(StrReverse(result))

                result = num + reversed

                count = count + 1
            Loop

            Console.WriteLine(number & " gets palindromic after " & count & " steps: " & result)
        Next

    End Sub

End Module