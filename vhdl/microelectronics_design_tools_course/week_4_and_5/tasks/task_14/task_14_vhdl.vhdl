library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity en_step_unit is
    port (
        x  : in  std_logic_vector(3 downto 0);
        up : in  std_logic;
        y  : out std_logic_vector(3 downto 0)
    );
end entity en_step_unit;

architecture ar_step_unit of en_step_unit is
begin
    y <= std_logic_vector(unsigned(x) + 1) when (up = '1' and x /= "1111") else
         std_logic_vector(unsigned(x) - 1) when (up = '0' and x /= "0000") else
         x;
end architecture ar_step_unit;