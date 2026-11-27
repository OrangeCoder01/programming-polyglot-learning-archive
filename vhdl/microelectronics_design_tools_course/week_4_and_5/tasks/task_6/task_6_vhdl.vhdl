library ieee;
use ieee.std_logic_1164.all;

entity en_decoder3to8 is
    port
    (
        input_bitsream: in std_logic_vector(2 downto 0);
        en: in std_logic;
        output_bitstream: out std_logic_vector(7 downto 0)
    );
end entity en_decoder3to8;

architecture ar_decoder3to8 of en_decoder3to8 is
    signal concatenator;
    begin
        concatenator <= en & input_bitstream;
        with (concatenator) select
            output_bitstream <= 
                                "00000001" when "1000",
                                "00000010" when "1001",
                                "00000100" when "1010",
                                "00001000" when "1011",
                                "00010000" when "1100",
                                "00100000" when "1101",
                                "01000000" when "1110",
                                "10000000" when "1111",
                                "00000000" when others;
end architecture ar_decoder3to8;