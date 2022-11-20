resource "aws_iam_role" "ssm" {

    name = "ec2-ssm-access"
    assume_role_policy = file("Policies/EC2Assumerole.json")


}

resource "aws_iam_policy" "ssm" {

    name = "SSMPolicy"
    policy = file("Policies/SSMPolicy.json")
}

resource "aws_iam_policy_attachment" "attach-ssm" {

    name = "Attach SSMPolicy"
    roles = [aws_iam_role.ssm.name]
    policy_arn = aws_iam_policy.ssm.arn
}

resource "aws_iam_instance_profile" "ssm-allow" {

    name = "SSM-Allow"
    role = aws_iam_role.ssm.name
}
