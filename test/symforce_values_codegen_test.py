# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

import os
import string

import symforce
import symforce.symbolic as sf
from symforce.codegen import values_codegen
from symforce.test_util import TestCase
from symforce.values import Values

SYMFORCE_DIR = os.path.dirname(os.path.dirname(__file__))
TEST_DATA_DIR = os.path.join(
    SYMFORCE_DIR, "test", "symforce_function_codegen_test_data", symforce.get_symbolic_api()
)


class SymforceValuesCodegenTest(TestCase):
    """
    Test symforce.codegen.values_codegen
    """

    def test_values_codegen(self) -> None:
        output_dir = self.make_output_dir("sf_values_codegen_test")

        values = Values()
        values["foo"] = sf.V3()
        values["foo2"] = 1.0
        values["foo_bar"] = sf.Rot3()
        values["foo_bar2"] = sf.Rot2()
        values["foo_baz"] = sf.M22()

        # Add a bunch of symbols with similar names to stress test
        for i in range(1, 5):
            for letter in string.ascii_lowercase:
                values[letter * i] = sf.Symbol(letter)

        values_codegen.generate_values_keys(values, output_dir)

        self.compare_or_update_directory(
            actual_dir=os.path.join(output_dir),
            expected_dir=os.path.join(TEST_DATA_DIR, "values_codegen_test_data"),
        )


if __name__ == "__main__":
    TestCase.main()
