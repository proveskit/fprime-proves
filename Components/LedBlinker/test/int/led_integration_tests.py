def test_cmd_no_op(fprime_test_api):
    """Test command CMD_NO_OP

    Test that CMD_NO_OP can be sent and return without and errors
    """
    fprime_test_api.send_and_assert_command("cmdDisp.CMD_NO_OP")
