def zipping (s)
    return_s = ""
    s.each_char { |ch|
        if ch != ' '
            return_s += ch
        end
    }
    return return_s
end

def extractNumbers(s)
    first_s = ""
    second_s = ""
    isFirst = true
    s.each_char { |ch|
        isFirst = false if ch == "+" or ch == "*"
        if isFirst
            first_s += ch
        else
            second_s += ch
        end
    }
    return first_s.to_i(9), second_s.to_i(9)
end


input_s = gets.chomp
zipped_s = zipping(input_s)
first, second = extractNumbers(zipped_s)
print "#{first + second}\n"
