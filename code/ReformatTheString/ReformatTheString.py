class Solution:
    def reformat(self, s: str) -> str:
        letter = []
        digit = []
        length_letter = 0
        length_digit = 0
        
        for i in s:
            if 'a' <= i <= 'z':
                letter.append(i)
                length_letter += 1
            else:
                digit.append(i)
                length_digit += 1
        
        output = []
        
        if abs(length_letter-length_digit) >= 2:
            return ""
        elif length_letter > length_digit:
            for i in range(length_digit):
                output.extend([letter[i], digit[i]])
            output.append(letter[length_letter-1])
        elif length_digit > length_letter:
            for i in range(length_letter):
                output.extend([digit[i], letter[i]])
            output.append(digit[length_digit-1])
        else:
            for i in range(length_digit):
                output.extend([letter[i], digit[i]])
                
        return ''.join(output)
