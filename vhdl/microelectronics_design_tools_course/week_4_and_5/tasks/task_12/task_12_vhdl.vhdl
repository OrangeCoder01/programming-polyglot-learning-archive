library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity en_signed_flags is
    port (
        x              : in  std_logic_vector(7 downto 0);
        zero, neg, pos : out std_logic
    );
end entity en_signed_flags;

architecture ar_signed_flags of en_signed_flags is
begin
    zero <= '1' when signed(x) = 0 else '0';
    neg  <= '1' when signed(x) < 0 else '0';
    pos  <= '1' when signed(x) > 0 else '0';
end architecture ar_signed_flags;