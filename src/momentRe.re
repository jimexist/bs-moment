/* duration */
module Duration = {
  type t;
  external humanize : t => string = "" [@@bs.send];
  external milliseconds : t => int = "" [@@bs.send];
  external asMilliseconds : t => int = "" [@@bs.send];
  external seconds : t => int = "" [@@bs.send];
  external asSeconds : t => int = "" [@@bs.send];
  external minutes : t => int = "" [@@bs.send];
  external asMinutes : t => int = "" [@@bs.send];
  external hours : t => int = "" [@@bs.send];
  external asHours : t => int = "" [@@bs.send];
  external days : t => int = "" [@@bs.send];
  external asDays : t => int = "" [@@bs.send];
  external weeks : t => int = "" [@@bs.send];
  external asWeeks : t => int = "" [@@bs.send];
  external months : t => int = "" [@@bs.send];
  external asMonths : t => int = "" [@@bs.send];
  external years : t => int = "" [@@bs.send];
  external asYears : t => int = "" [@@bs.send];
  external toJSON : t => string = "" [@@bs.send];
  external asUnitOfTime : t => string => int = "as" [@@bs.send];
};

external duration : int => string => Duration.t = "" [@@bs.module "moment"];

external duration_millis : int => Duration.t = "duration" [@@bs.module "moment"];

external duration_format : string => Duration.t = "duration" [@@bs.module "moment"];

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
  external format : t => format::string => string = "" [@@bs.send];
  external fromNow : t => withoutSuffix::option bool => string = "" [@@bs.send];
  external fromMomemnt : t => other::t => format::option string => string = "from" [@@bs.send];
  external toNow : t => withoutSuffix::option bool => string = "" [@@bs.send];
  external toMoment : t => other::t => format::string => string = "to" [@@bs.send];
  external valueOf : t => int = "" [@@bs.send];
  external daysInMonth : t => int = "" [@@bs.send];
  external toJSON : t => string = "" [@@bs.send];
};

/* parse */
external moment_now : unit => Moment.t = "moment" [@@bs.module];

external moment_default_format : string => Moment.t = "moment" [@@bs.module];

external moment_with_format : string => string => Moment.t = "moment" [@@bs.module];

external moment_with_formats : string => list string => Moment.t = "moment" [@@bs.module];

external moment_with_timestamp : int => Moment.t = "moment" [@@bs.module];

external moment_with_components : list int => Moment.t = "moment" [@@bs.module];

let moment ::format=? value =>
  switch format {
  | Some f => moment_with_format value f
  | None => moment_default_format value
  };
