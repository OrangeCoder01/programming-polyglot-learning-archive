library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity en_max_of_three is
    port 
    (
        a, b, c : in  std_logic_vector(3 downto 0);
        y       : out std_logic_vector(3 downto 0)
    );
end entity en_max_of_three;

architecture ar_max_of_three of en_max_of_three is
begin
    y <= a when (unsigned(a) >= unsigned(b) and unsigned(a) >= unsigned(c)) else
         b when (unsigned(b) >= unsigned(c)) else
         c;
end architecture ar_max_of_three;