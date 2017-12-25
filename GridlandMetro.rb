def inputData
    firstInput = gets.chomp
    row_s = ""
    column_s = ""
    input_s = ""
    phase = 0

    firstInput.each_char do |ch|
        if ch == " "
            phase += 1
            next
        end

        case phase
        when 0 then
            row_s += ch
        when 1 then
            column_s += ch
        when 2 then
            input_s += ch
        end
    end
    return row_s.to_i, column_s.to_i, input_s.to_i
end

row, column, line = inputData
all = row * column
cost = 0
ary = Array.new(row).map{Array.new(column, 0)}
line.times do
    row, start, last = inputData
    start.upto(last) do |pos|
        if ary[row-1][pos-1] == 0 then
            ary[row-1][pos-1] = 1
            #print row-1, pos-1
            cost += 1
        end
    end
end

print "#{all - cost}\n"
