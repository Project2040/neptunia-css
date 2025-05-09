<?php

/* testStandard */
$fn1 = fn($x) => $x + $y;

/* testMixedCase */
$fn1 = Fn($x) => $x + $y;

/* testWhitespace */
$fn1 = fn ($x) => $x + $y;

/* testComment */
$fn1 = fn /* comment here */ ($x) => $x + $y;

/* testHeredoc */
$fn1 = fn() => <<<HTML
fn
HTML;

/* testFunctionName */
function fn() {}

/* testNestedOuter */
$fn = fn($x) => /* testNestedInner */ fn($y) => $x * $y + $z;

/* testNestedSharedCloserOuter */
$foo = foo(fn() => /* testNestedSharedCloserInner */ fn() => bar() === true);

/* testFunctionCall */
$extended = fn($c) => $callable($factory($c), $c);

/* testChainedFunctionCall */
$result = Collection::from([1, 2])
    ->map(fn($v) => $v * 2)
    ->reduce(/* testFunctionArgument */ fn($tmp, $v) => $tmp + $v, 0);

/* testClosure */
$extended = fn($c) => $callable(function() {
    for ($x = 1; $x < 10; $x++) {
        echo $x;
    }

    echo 'done';
}, $c);

/* testArrayIndex */
$found = in_array_cb($needle, $haystack, fn($array, $needle) => $array[2] === $needle);

$result = array_map(
    /* testReturnType */
    static fn(int $number) : int => $number + 1,
    $numbers
);

/* testReference */
fn&($x) => $x;

/* testGrouped */
(fn($x) => $x) + $y;

/* testArrayValue */
$a = [
    'a' => fn() => return 1,
];

/* testArrayValueNoTrailingComma */
$a = [
    'a' => fn() => foo()
];

/* testYield */
$a = fn($x) => yield 'k' => $x;

/* testNullableUnqualifiedClassName */
$a = fn(?\DateTime $x) : ?\DateTime => $x;

/* testNamespaceRelativeClassNameInTypes */
$fn = fn(namespace\Foo $a) : ?namespace\Foo => $a;

/* testSelfReturnType */
fn(self $a) : self => $a;

/* testParentReturnType */
fn(parent $a) : parent => $a;

/* testCallableReturnType */
fn(callable $a) : callable => $a;

/* testArrayReturnType */
fn(array $a) : array => $a;

/* testStaticReturnType */
fn(array $a) : static => $a;

/* testFalseReturnType */
fn(array $a) : false => $a;

/* testTrueReturnType */
fn(array $a) : True => $a;

/* testNullReturnType */
fn(array $a) : null => $a;

/* testUnionParamType */
$arrowWithUnionParam = fn(int|float $param) : SomeClass => new SomeClass($param);

/* testUnionReturnType */
$arrowWithUnionReturn = fn($param) : int|float => $param | 10;

/* testUnionReturnTypeWithTrue */
$arrowWithUnionReturn = fn($param) : int|true => $param | 10;

/* testUnionReturnTypeWithFalse */
$arrowWithUnionReturn = fn($param) : string|FALSE => $param | 10;

/* testIntersectionParamType */
$arrowWithIntersectionParam = fn(Traversable&Countable $param) : int => (new SomeClass($param))->getValue();

/* testIntersectionReturnType */
$arrowWithIntersectionReturn = fn($param) : \MyFoo&SomeInterface => new SomeClass($param);

/* testDNFParamType */
$arrowWithDNFParam = fn((Traversable&Countable)|null $param) : SomeClass => new SomeClass($param) ?? null;

/* testDNFReturnType */
$arrowWithDNFReturn = fn($param) : false|(\MyFoo&SomeInterface) => new \MyFoo($param) ?? false;

/* testDNFParamTypeWithReturnByRef */
$arrowWithDNFParamReturnByRef = fn &((A&B)|null $param) => $param * 10;

/* testTernary */
$fn = fn($a) => $a ? /* testTernaryThen */ fn() : string => 'a' : /* testTernaryElse */ fn() : string => 'b';

/* testTernaryWithTypes */
$fn = fn(int|null $a) : array|null => $a ? null : [];

function matchInArrow($x) {
    /* testWithMatchValue */
    $fn = fn($x) => match(true) {
        1, 2, 3, 4, 5 => 'foo',
        default => 'bar',
    };
}

function matchInArrowAndMore($x) {
    /* testWithMatchValueAndMore */
    $fn = fn($x) => match(true) {
        1, 2, 3, 4, 5 => 'foo',
        default => 'bar',
    } . 'suffix';
}

function arrowFunctionInMatchWithTrailingComma($x) {
    return match ($x) {
        /* testInMatchNotLastValue */
        1 => fn($y) => callMe($y),
        /* testInMatchLastValueWithTrailingComma */
        default => fn($y) => callThem($y),
    };
}

function arrowFunctionInMatchNoTrailingComma1($x) {
    return match ($x) {
        1 => fn($y) => callMe($y),
        /* testInMatchLastValueNoTrailingComma1 */
        default => fn($y) => callThem($y)
    };
}

function arrowFunctionInMatchNoTrailingComma2($x) {
    return match ($x) {
        /* testInMatchLastValueNoTrailingComma2 */
        default => fn($y) => 5 * $y
    };
}

/* testConstantDeclaration */
const FN = 'a';

/* testConstantDeclarationLower */
const fn = 'a';

class Foo {
    /* testStaticMethodName */
    public static function fn($param) {
        /* testNestedInMethod */
        $fn = fn($c) => $callable($factory($c), $c);
    }

    public function foo() {
        /* testPropertyAssignment */
        $this->fn = 'a';
    }
}

$anon = new class() {
    /* testAnonClassMethodName */
    protected function fN($param) {
    }
}

/* testNonArrowStaticMethodCall */
$a = Foo::fn($param);

/* testNonArrowConstantAccess */
$a = MyClass::FN;

/* testNonArrowConstantAccessMixed */
$a = MyClass::Fn;

/* testNonArrowObjectMethodCall */
$a = $obj->fn($param);

/* testNonArrowObjectMethodCallUpper */
$a = $obj->FN($param);

/* testNonArrowNamespacedFunctionCall */
$a = MyNS\Sub\Fn($param);

/* testNonArrowNamespaceOperatorFunctionCall */
$a = namespace\fn($param);

/* testNonArrowFunctionNameWithUnionTypes */
function fn(int|float $param) : string|null {}

/* testLiveCoding */
// Intentional parse error. This has to be the last test in the file.
$fn = fn
