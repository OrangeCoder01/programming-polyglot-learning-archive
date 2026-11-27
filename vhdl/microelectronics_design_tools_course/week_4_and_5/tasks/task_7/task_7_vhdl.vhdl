library ieee;
use ieee.std_logic_1164.all;

entity en_mux_8_to_1 is
    port
    (
      input_bitstream: in std_logic_vector(7 downto 0);
      output_bit: out std_logic;
      sel: in std_logic_vector( 2 downto 0)  
    );
end entity en_mux_8_to_1;

architecture ar_mux_8_to_1 of en_mux_8_to_1 is
    begin
        with (sel) select
            output_bit <= input_bitsream(0) when "000",
                          input_bitsream(1) when "001",
                          input_bitsream(2) when "010",
                          input_bitsream(3) when "011",
                          input_bitsream(4) when "100",
                          input_bitsream(5) when "101",
                          input_bitsream(6) when "110",
                          input_bitsream(0) when "111",
                          '0' when others;
end architecture ar_mux_8_to_1;