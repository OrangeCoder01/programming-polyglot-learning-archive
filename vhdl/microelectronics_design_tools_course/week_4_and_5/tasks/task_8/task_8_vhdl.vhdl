library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity en_hex_to_7_seg_dec is
    port
    (
        input_letter_value: in unsigned(3 downto 0);
        output_letter_bcd: out std_logic_vector(6 downto 0) -- a b c d e f g
    );
end entity en_hex_to_7_seg_dec;

architecture ar_hex_to_7_seg_dec of en_hex_to_7_seg_dec is
    begin
        with (to_integer(input_letter_value)) select
            output_letter_bcd <= "1111110" when 0,
                                 "0110000" when 1,
                                 "1101101" when 2,
                                 "1111001" when 3,
                                 "0110011" when 4,
                                 "1011011" when 5,
                                 "1011111" when 6,
                                 "1110000" when 7,
                                 "1111111" when 8,
                                 "1111011" when 9,
                                 "1110111" when 10,
                                 "0011111" when 11,
                                 "1001110" when 12,
                                 "0111101" when 13,
                                 "1001111" when 14,
                                 "1000111" when 15,
                                 "0000000" when others;
end architecture ar_hex_to_7_seg_dec;