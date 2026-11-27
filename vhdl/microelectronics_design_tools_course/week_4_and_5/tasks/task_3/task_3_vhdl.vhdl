library ieee;
use ieee.std_logic_1164.all;

entity en_dec38 is
    port
    (
        en_n: in std_logic;
        input_bitstream: in std_logic_vector(2 downto 0);
        output_bitstrean: out std_logic_vector(7 downto 0)
    );
end entity en_dec38;

architecture ar_dec38 of en_dec38 is
    begin
        output_bitstream <= "00000000" when (en_n = '1') else
                            "00000001" when (input_bitstream = "000") else
                            "00000010" when (input_bitstream = "001") else
                            "00000100" when (input_bitstream = "010") else
                            "00001000" when (input_bitstream = "011") else
                            "00010000" when (input_bitstream = "100") else
                            "00100000" when (input_bitstream = "101") else
                            "01000000" when (input_bitstream = "110") else
                            "10000000" when (input_bitstream = "111");
end architecture ar_dec38;