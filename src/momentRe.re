/* duration */
module Duration = {
  type t;
  external humanize : t => unit => string = "" [@@bs.send];
  external milliseconds : t => unit => int = "" [@@bs.send];
  external asMilliseconds : t => unit => int64 = "" [@@bs.send];
  external seconds : t => unit => int = "" [@@bs.send];
  external asSeconds : t => unit => int64 = "" [@@bs.send];
  external minutes : t => unit => int = "" [@@bs.send];
  external asMinutes : t => unit => int64 = "" [@@bs.send];
  external hours : t => unit => int = "" [@@bs.send];
  external asHours : t => unit => int64 = "" [@@bs.send];
  external days : t => unit => int = "" [@@bs.send];
  external asDay : t => unit => int64 = "" [@@bs.send];
  external weeks : t => unit => int = "" [@@bs.send];
  external asWeeks : t => unit => int64 = "" [@@bs.send];
  external months : t => unit => int = "" [@@bs.send];
  external asMonths : t => unit => int64 = "" [@@bs.send];
  external years : t => unit => int = "" [@@bs.send];
  external asYears : t => unit => int64 = "" [@@bs.send];
  external toJSON : t => unit => string = "" [@@bs.send];
};

module Moment = {
  type t;
  external isValid : t => bool = "" [@@bs.send];
  external isBefore : t => t => bool = "" [@@bs.send];
  external isAfter : t => t => bool = "" [@@bs.send];
  external isSame : t => t => bool = "" [@@bs.send];
  external isSameOrBefore : t => t => bool = "" [@@bs.send];
  external isSameOrAfter : t => t => bool = "" [@@bs.send];
  external isBetween : t => t => t => bool = "" [@@bs.send];
  external isDST : t => bool = "" [@@bs.send];
  external isLeapYear : t => bool = "" [@@bs.send];
  /* display */
  external format : t => format::option string => string = "" [@@bs.send];
  external fromNow : t => withoutSuffix::option bool => string = "" [@@bs.send];
  external from : t => other::t => format::option string => string = "" [@@bs.send];
  external toNow : t => withoutSuffix::option bool => string = "" [@@bs.send];
  external _to : t => other::t => format::option string => string = "" [@@bs.send];
  external valueOf : t => unit => int64 = "" [@@bs.send];
  external daysInMonth : t => unit => int = "" [@@bs.send];
  external toJSON : t => unit => string = "" [@@bs.send];
  external duration : t => duration::int => durationUnit::option string => Duration.t =
    "" [@@bs.send];
};

/* parse */
external moment_now : unit => Moment.t = "moment" [@@bs.module];

external moment_default_format : string => Moment.t = "moment" [@@bs.module];

external moment_with_format : string => string => Moment.t = "moment" [@@bs.module];

external moment_with_formats : string => list string => Moment.t = "moment" [@@bs.module];

external moment_with_timestamp : int64 => Moment.t = "moment" [@@bs.module];

external moment_with_components : list int => Moment.t = "moment" [@@bs.module];

let moment ::format=? value =>
  switch format {
  | Some f => moment_with_format value f
  | None => moment_default_format value
  };
